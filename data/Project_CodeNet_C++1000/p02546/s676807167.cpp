#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
int main(void){
    // Your code here!
 int n;
 string s;
 cin >> s;
 n=s.length();
 if(s[n-1]=='s')
 s.append(1,'e');
 s.append(1,'s');
 cout << s;
 return 0;
}