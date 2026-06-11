#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <ctime>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define TT int test_cases; cin >> test_cases; while(test_cases--)
#define TT1 int test_cases=1; while(test_cases--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
typedef long long int ll;

 
int main() {
    
    FAST;
    TT1{
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int sum=0;
        for(int i=0;i<k;i++) sum+=a[i];
        cout<<sum<<"\n";
    }
}