#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
int main(){
	int h1 , m1, h2, m2 , k;
	cin>>h1>>m1>>h2>>m2>>k;
	if(h2 == 0){
       h2 = 12;
	}
	int l = h1*60 + m1;
    int y = h2*60 + m2;
    cout<<y-l-k<<endl;
}