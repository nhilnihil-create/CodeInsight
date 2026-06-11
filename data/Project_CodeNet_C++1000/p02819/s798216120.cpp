#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;

#define MAX 100020
int main(void){
    
int x;
cin>>x;

vector<bool> vec(MAX+1,true);

for(int i=2; i*i<=MAX;i++){
    if(vec[i]==true){
        for(int j=i*i; j<=MAX;j+=i){
            vec[j]=false;
        }    
    }
    
}

vector<int> prim;
 for(int i=2; i<=MAX;i++){
     if(vec[i]==true)
        prim.push_back(i);
 }
 
 auto it= lower_bound(prim.begin(), prim.end(),x);
    cout<<*it;


}