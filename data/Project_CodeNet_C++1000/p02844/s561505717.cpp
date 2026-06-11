#include<bits/stdc++.h>
using namespace std;
#define N 250
#define ll long long
#define pb push_back
#define pi pair<ll , ll>
#define mp make_pair
bool check(string v , string& str){
	int j = 0 ; 
 for(int i = 0 ; i <(int)str.length() && j < (int)v.length() ; i++){
    if(v[j] == str[i]){
	 j++;
	 if(j == (int)v.length())return true;
	}
 }
 return false;
}
int main(){
int n;
cin>>n;
string str;
cin>>str;
set<string> v;
for(int i = 0 ; i < 10 ; i++){
 for(int j = 0 ; j < 10 ; j++){
   for(int k = 0 ; k < 10 ; k++){
        int l =  i*100 + j*10 + k;
        string s ="123";
        s[0] = char(i+'0');
        s[1] = (j+'0');
        s[2] = (k+'0');
       v.insert(s);
   }
 }
}

int ans = 0;
for(auto it : v){
   if(check(it , str) && it.length() == 3){
    ans++;
   }
}
cout<<ans<<endl;
}
