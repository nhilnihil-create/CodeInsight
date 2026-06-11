#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020

int main(){
string s;
int n;
cin>>n>>s;

for(int i=0;i<s.length();i++){
    if(s[i]+n > 'Z')
        {
            int diff=  s[i] +n -'Z';
            s[i]='A'+diff -1;
        }        
    else
        s[i]= s[i]+n;
}
cout<<s;
}