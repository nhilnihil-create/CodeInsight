#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define filein freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);


void fun1(int* a,int* b){
    int sum=*a+*b;
    int dif=abs(*a-*b);
    //cout<<sum<<dif<<"\n";
    *a=sum;
    *b=dif;
}


int main() {
    int k;
    cin>>k;
    long long a[100005]={0,1,2,3,4,5,6,7,8,9};
    int count=10;
    int index=1;
    while (count<100001){
        long long t=a[index]%10;
        for (long long i = t-1; i <=t+1 ; ++i) {
            if (i>-1 && i<10)
                a[count++]=a[index]*10+i;
        }

        index++;
    }


    //for (int j = 0; j <10000 ; ++j) {
    //    cout<<a[j]<<" ";

   // }
   cout<<a[k];





}
