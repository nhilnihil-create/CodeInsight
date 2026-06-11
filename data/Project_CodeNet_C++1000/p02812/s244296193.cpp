#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
int  n;
string s;
string a="ABC";
cin>>n>>s;

int pos=0, count=0;

while((pos= s.find(a, pos))!=std::string::npos){
    count++;
    pos= pos+ a.length();
}
cout<<count;



}

