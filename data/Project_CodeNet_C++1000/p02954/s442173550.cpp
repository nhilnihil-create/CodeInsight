#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int NUM = 2e5 + 5;

int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        string s; cin>>s;
        int n = s.size();
        char curr = 'R';
        int count[2];
        count[0]=0; count[1]=0;
        int ans[n];
        int lastp = -1;
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            if(s[i]==curr) count[i%2]++;
            else{
                if(s[i]=='L'){
                    lastp = i-1;
                    ans[lastp] += count[lastp%2];
                    ans[lastp+1] += count[(lastp+1)%2];
                }
                else{
                    ans[lastp] += count[lastp%2];
                    ans[lastp+1] += count[(lastp+1)%2];
                }
                count[0]=0;
                count[1]=0;
                curr=s[i];
                count[i%2]++;
            }
        }
        ans[lastp] += count[lastp%2];
        ans[lastp+1] += count[(lastp+1)%2];
        for(auto x:ans) cout<<x<<" ";
    }   
}
