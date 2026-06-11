// B - Tag
#include <bits/stdc++.h>
using namespace std;

int main(){
	int64_t a,v,b,w,t; cin>>a>>v>>b>>w>>t;
	puts(abs(a-b) <= (v-w)*t? "YES":"NO");
}
