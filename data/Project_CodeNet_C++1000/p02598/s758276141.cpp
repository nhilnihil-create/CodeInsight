#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
using namespace std;
const int N = 200000;
int arr[N+5];
int longest_log = 0;
int n, k;

bool do_cut(int len){
    int cuts = 0;
    for(int i=0; i<n; i++){
        cuts+=(arr[i]-1)/len;
    }
    return cuts<=k;
}

int main(){
    AC
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        longest_log = max(longest_log, arr[i]);
    }

    int l=1, r=longest_log;
    while(l<r){
        int m = l+(r-l)/2;
        if(do_cut(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l<<endl;

}