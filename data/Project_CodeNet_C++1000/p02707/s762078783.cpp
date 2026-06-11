#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    int n;
    cin>>n;
    int arr[n+1]={};
    for(int i=1;i<n;i++) {
        int x;
        cin>>x;
        arr[x]++;
    }
    for(int i=1;i<=n;i++) {
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
