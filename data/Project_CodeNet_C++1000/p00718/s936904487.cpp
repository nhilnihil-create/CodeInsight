#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){

  int n;
  string sa,sd;
  int fa,fd;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> sa >> sd;
    fa = 0;
    fd = 0;
    for(int j=0;j<sa.length();j++){
      if(sa[j] == 'm')
	{
	  if( 2 <= sa[j-1]-'0' && sa[j-1]-'0' <= 9)
	    {
	      fa += 1000*(sa[j-1]-'0');
		continue;
	    }
	  fa += 1000;
	} 
      if(sa[j] == 'c')
	{
	  if( 2 <= sa[j-1]-'0' && sa[j-1]-'0' <= 9)
	    {
	      fa += 100*(sa[j-1]-'0');
		continue;
	    }
	  fa += 100;
	} 
      if(sa[j] == 'x')
	{
	  if( 2 <= sa[j-1]-'0' && sa[j-1]-'0' <= 9)
	    {
	      fa += 10*(sa[j-1]-'0');
		continue;
	    }
	  fa += 10;
	} 
      if(sa[j] == 'i')
	{
	  if( 2 <= sa[j-1]-'0' && sa[j-1]-'0' <= 9)
	    {
	      fa += 1*(sa[j-1]-'0');
		continue;
	    }
	  fa += 1;
	} 
     
    }




 for(int j=0;j<sd.length();j++){
      if(sd[j] == 'm')
	{
	  if( 2 <= sd[j-1]-'0' && sd[j-1]-'0' <= 9)
	    {
	      fd += 1000*(sd[j-1]-'0');
		continue;
	    }
	  fd += 1000;
	} 
      if(sd[j] == 'c')
	{
	  if( 2 <= sd[j-1]-'0' && sd[j-1]-'0' <= 9)
	    {
	      fd += 100*(sd[j-1]-'0');
		continue;
	    }
	  fd += 100;
	} 
      if(sd[j] == 'x')
	{
	  if( 2 <= sd[j-1]-'0' && sd[j-1]-'0' <= 9)
	    {
	      fd += 10*(sd[j-1]-'0');
		continue;
	    }
	  fd += 10;
	} 
      if(sd[j] == 'i')
	{
	  if( 2 <= sd[j-1]-'0' && sd[j-1]-'0' <= 9)
	    {
	      fd += 1*(sd[j-1]-'0');
		continue;
	    }
	  fd += 1;
	} 
     
    }
 // cout << fa << " "  <<fd <<endl;    

 int ff = fa+fd;    
 char ch[20000];
 sprintf(ch,"%d",ff);
 string s;
 string ans;
 s.append(ch);
 for(int i=0;i<s.length();i++){
   if(s[i]-'0' == 0){
continue;
   }
   else if(2 <= s[i]-'0' && s[i]-'0' <= 9){
     cout << s[i];
   }
   if(s.length() == 4){
     if(i == 0)cout << 'm';
     else if(i == 1)cout << 'c';
     else if(i == 2)cout << 'x';
     else if(i == 3)cout <<'i';
   }
   else if(s.length() == 3){
     if(i == 0)cout << 'c';
     else if(i == 1)cout << 'x';
     else if(i == 2)cout <<'i';
   }
 else if(s.length() == 2){
     if(i == 0)cout << 'x';
     else if(i == 1)cout <<'i';
   }
 else if(s.length() == 1){
    cout <<'i';
   }
   



 }cout << endl;







    
  }
  





}