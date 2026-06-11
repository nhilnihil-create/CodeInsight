#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
 cin>>s;
 long long n=s.size();
 if(s[n-1]=='2'||s[n-1]=='9'||s[n-1]=='7'||s[n-1]=='5'||s[n-1]=='4')cout<<"hon";
 else if(s[n-1]=='8'||s[n-1]=='0'||s[n-1]=='1'||s[n-1]=='6')cout<<"pon";
 else cout<<"bon";


    return 0;}


