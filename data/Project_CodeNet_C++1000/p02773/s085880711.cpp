/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll N;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
	map<string , int> stringmaps;
	cin>>N;
    string s;
    for(ll i = 0 ; i<N ; i++){
    	cin>>s;
    	stringmaps[s]++;
    }
    ll maximum = 0;
    for(const auto &x: stringmaps){
    	ll v;
        v =  x.second;
        if(v>maximum) maximum = v;
    }


    for(auto it = stringmaps.begin() ; it != stringmaps.end() ; it++){
    	if(it->second == maximum)
    		cout<<it->first<<'\n';
    }



}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}
