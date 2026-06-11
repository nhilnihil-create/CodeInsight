#include<map>
#include<set>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
#include<iostream>
#include "bits/stdc++.h"
#define IO ios_base::sync_with_stdio(false);cin.tie(0);
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
using namespace std;

void solu (){

}

int main(void){
	int n,x,t;
	while (cin>>n>>x>>t){
        if(n%x!=0){
            cout<<(n/x+1)*t<<endl;
        }
        else {
            cout<<(n/x)*t<<endl;
        }
	}

	return 0;
}
