#include <bits/stdc++.h>
using namespace std;

int main() {
long int n,m;
string st;
cin>>n>>m;
long int s[m],p[m];
for(int i=0;i<m;i++){
    cin>>p[i]>>st;
    if(st=="AC"){
        s[i]=1;
    }
    else if(st=="WA") {
     s[i]=0;   
    }
}
long int penly=0,points=0;
unordered_map<int,int> done,pen;
for(int i=0;i<m;i++){
    if(done[p[i]]==0){
        if(s[i]==0){
            pen[p[i]]++;
        }
        else if(s[i]==1){
            points++;
            done[p[i]]=1;
        }
    }
}
for(int i=0;i<m;i++){
    if(done[p[i]]==1){
        penly+=pen[p[i]];
        done[p[i]]=0;
    }
}
cout<<points<<" "<<penly;
	return 0;
}
