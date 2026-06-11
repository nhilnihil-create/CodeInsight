#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
#define PI 2 * acos(0.0)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 
bool is_palindrome(string s){
     ll j = s.length()-1;
     ll i = 0;
     while(i < j){
         if(s[i] != s[j]){
             return false;
         }
         i++;
         j--;
     }
     ll n = s.length();
     ll o = ((n-1)/2) - 1;
     i = 0;
     while(i < o){
         if(s[i] != s[o]) return false;
         i++;
         o--;
     }
     ll r = (n+3)/2 - 1;
     j = n-1;
     while(r < j){
         if(s[r] != s[j]) return false;
         r++;
         j--;
     }
     return true;
}
int main(){
    fast_io 
    string s;
    cin>>s;
    if(is_palindrome(s) == true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
