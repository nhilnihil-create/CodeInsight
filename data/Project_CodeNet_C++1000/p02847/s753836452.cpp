 #include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
    
using namespace std;
bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
} 

  
int main(){
    IOS;
 
 string s;
 cin>>s;
 if(s=="SUN") cout<<"7\n";
 else if(s=="SAT") cout<<"1\n";
 else if(s=="MON") cout<<"6\n";
 else if(s=="TUE") cout<<"5\n";
 else if(s=="WED") cout<<"4\n";
 else if(s=="THU") cout<<"3\n";
 else cout<<"2\n";
  
    return 0;}