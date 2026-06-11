#include<bits/stdc++.h>
using namespace std;
int main(){
	//r p s - 0 1 2
	int n,k;cin>>n>>k;
	vector<int >pl(n);
	vector<int >nos(n,0);
	int cost[3];
	cin>>cost[0]>>cost[2]>>cost[1]; //r s p
	string s;
	cin>>s;
	//convert rps
	for(int i=0;i<n;i++){
	    if(s[i]=='r')pl[i]=0;
	    else if(s[i]=='p')pl[i]=1;
	    else pl[i]=2;
	}
	//for first k
	int fin=0;
	for(int i=0;i<k;i++)
	    {fin+=cost[(pl[i]+1)%3];nos[i]=1;}
    //cout<<fin<<'\n';
	int prev;
	for(int i=k;i<n;i++){
	    prev = i-k;
	    //nos[i][(pl[i]+1)%3]=cost[(pl[i]+1)%3];
        if((pl[i]+1)%3!=(pl[prev]+1)%3 || nos[prev]==0){
            fin+=cost[(pl[i]+1)%3];nos[i]=1;
        }
	    //cout<<fin<<'\n';
	}
	cout<<fin;
}