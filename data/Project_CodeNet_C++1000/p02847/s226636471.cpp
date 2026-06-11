#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
#define d double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  if(s=="SUN"){
  	cout<<"7"<<endl;
  }
  
  else if(s=="SAT"){
  	cout<<"1"<<endl;
  	
  }
  else if(s=="FRI"){
  	cout<<"2"<<endl;
  }
  else if(s=="THU"){
  	cout<<"3"<<endl;
  }
  else if(s=="WED"){
  	cout<<"4"<<endl;
  }
  else if(s=="TUE"){
  	cout<<"5"<<endl;
  }
  else if(s=="MON"){
  	cout<<"6"<<endl;
  }
  
  return 0;
}