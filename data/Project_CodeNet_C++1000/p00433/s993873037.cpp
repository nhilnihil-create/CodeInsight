#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define RE return 0;

int main(){
  int suma=0,sumb=0;
  for(int i=0; i<4; i++){
    int a;
    cin>>a;
    suma+=a;
  }
  for(int i=0; i<4; i++){
    int b;
    cin>>b;
    sumb+=b;
  }
  
  cout<<(suma>=sumb ? suma:sumb)<<en
}
