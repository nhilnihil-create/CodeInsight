#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,ans;
cin >>a;
cin >>b;
cin >>c;

ans = c - (a-b);

cout <<max(ans,0) <<endl;
}
