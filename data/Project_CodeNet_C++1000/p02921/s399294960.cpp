/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
   int n,i,j,k,l=0;
   string s1,s2;
   cin>>s1;
   cin>>s2;
   if(s1[0]==s2[0]) l++;
   if(s1[1]==s2[1]) l++;
   if(s1[2]==s2[2]) l++;
   cout<<l;
  }