#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

void test_case()
{
    int n, j=1;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        if(a[i]==j) {
            j++;
        }
    }
    if(j==1){
        cout<<"-1";
    } else {
        cout<<n-j+1;
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
