#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long int
#define d double 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	
     string s;
	 cin>>s;
	 if(s[2]==s[3]&&s[4]==s[5]){
	   cout<<"Yes"<<endl;	
	 }   
	 else {
      cout<<"No"<<endl;	
	 }
    
    return 0;   
}