#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstdlib>
#include<ctime>
#include<random>
#define ll long long
using namespace std;

int x;

int main(){
    scanf("%d",&x);
    int ans=(x/500)*1000;
    x%=500;
    ans+=(x/5)*5;
    printf("%d\n",ans);
}