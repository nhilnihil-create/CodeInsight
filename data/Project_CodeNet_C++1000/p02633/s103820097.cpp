#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<bitset>
#include<map>
#include<vector>
#define ll long long
#define mkp make_pair
#define x first
#define y second
#define pli pair<ll,int>
using namespace std;
int x,y;
int gcd(int x,int y){if(!y)return x;return gcd(y,x%y);}
int main(){
	scanf("%d",&x);
	y=360/gcd(360,x);
	cout<<y;
}