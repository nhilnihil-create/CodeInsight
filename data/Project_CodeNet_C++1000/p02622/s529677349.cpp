#include <bits/stdc++.h>

using namespace std;

#define l long long
#define ul unsigned long long
#define ui unsigned int
#define PI  3.141592653589793238462643383279502884
#define f(i0,n0) for(long long i0 = 0; i0 < n0; ++i0)
#define f1(i1,n1) for(long long i1 = 1; i1 <= n1; ++i1)
#define finv(i2,n2) for(long long i2=n2;i2>0;--i2)
#define sq(a) (a)*(a)
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



/*Function to left Rotate arr[] of
  size n by 1*/
void leftRotatebyOne(char arr[], int n){
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    arr[i] = temp;
}

void reverseArray(char arr[], int start, int end){
    while (start < end)
    {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to right rotate arr[] of size n by d
void rightRotate(char arr[], int d){
    int n=26;
    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
}
//Function to left rotate arr[] of size n by d
void leftRotate(char arr[], int d){
    int n=26;
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}
bool isPowerOfTwo(auto n){
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}
bool isprime(auto n) {
    if(n<=1)return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(l i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) return false;
    return true;
}
bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'|| ch=='u' || ch=='y' || ch=='Y' || ch=='A'||ch=='E'||ch=='I'||ch=='O'|| ch=='U')return true;
    else return false;
}
l fast_power(auto x, auto y){

    if (y == 0)
        return 1;
    l temp = fast_power(x, y / 2) ;
    temp = sq(temp);
    if (y&1)
        temp = (temp*x);
    return temp;

}

void merge(int *a, int s, int e){
    int mid=(s+e)/2;

    int i=s, j=mid+1, k=s;

    int temp[1000];

    //sorting
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }

    //copying the rest
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }

    //copy all the elements in the original array
    for(int i=s;i<=e;i++) a[i]=temp[i];

}
void mergeSort(int a[], int s, int e){
    //base case:
    if(s>=e)return;

    //follow 3 steps:

    //1. divide
    int mid=(s+e)/2;

    //2.recursively sort the arrays
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);


    //3.merge the 2 parts
    merge(a,s,e);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Poker Cards transformer:
int CardToRank(char card){

    switch(card)
    {
        case 'T' :
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        default :
            return card-48;
    }
}

void reverseQueue(priority_queue<int>& Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.top());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}


int main()
{

    FASTIO
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    string s,t;
    cin>>s>>t;
    int counter=0;
    for(int i=0;s[i];++i)
    {
        if(s[i] != t[i])
            ++counter;
    }
    cout<<counter;

    return 0;
}
