#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
using namespace std;
#define LATTE 10000

int main(){
	int A,B,C;
	cin>>A>>B>>C;
	if(A<B && B<C) puts("Yes");
	else puts("No");
    return 0;
}