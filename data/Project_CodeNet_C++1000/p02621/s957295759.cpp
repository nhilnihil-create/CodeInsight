#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
vector <tuple<int,int,int>>relation;
set<int> pa;
set<int> pb;
int a;
int main(){
    scanf("%d",&a);
    a=a+a*a+a*a*a;
    printf("%d",a);
}