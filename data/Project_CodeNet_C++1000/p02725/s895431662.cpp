//#include<bits/stdc++.h> using namespace std;
#include<iostream>
using namespace std;
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue> //priority_queue inside queue
#include<deque>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
#define f(i,start,end) for(i=start;i<=end;i++)
#define min_heap priority_queue<int, vector<int>, greater<int> >
#define max_heap priority_queue<int>
#define eb emplace_back

struct Point
{
    ll x, y;
};
/// compare function for sorting the points
bool cmp(Point p1, Point p2)
{
    if(p1.x!=p2.x) return p1.x<p2.x;
    return p1.y<p2.y; //p1.x==p2.x
}

bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
} //returns true if prime!

ll sum(ll x)
{
    ll res = 0;
    if(x%2==0){
        res = x/2;
        res *= (x+1);
    }
    else{
        res = (x+1)/2;
        res *= x;
    }
    return res;
}

int binary_search(int a[], int n, int x)
{
    int l = 0, r = n-1, m = 0;
    while(l<=r)
    {
        m = l + (r-l)/2;
        if(a[m]==x) return m;
        if(a[m]>x){ r = m-1; }
        else if(a[m]<x){ l = m+1; }
    }
    return -1;
}
/*
/// Quick Sort ///
int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1; // index fixed at -1 for low=0
    
    for(int j=low; j<=high-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
int quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
/// Quick Sort ///
*/


int main()
{
    fast;
    //int t=0,tc=0; cin >> tc; f(t,1,tc) //testcases
    {
        int i,j;
        int k,n; cin >> k >> n;
        int a[n]; f(i, 0, n-1) cin >> a[i];
        int ans = a[n-1]-a[0];
        int tmp;
        f(i, 1, n-1)
        {
            tmp = abs(a[i-1]+k-a[i]);
            ans = min(tmp, ans);
        }
        cout << ans << nl;
    }
    return 0;
}