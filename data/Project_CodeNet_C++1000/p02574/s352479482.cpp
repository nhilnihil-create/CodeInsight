#include <bits/stdc++.h>
using namespace std;
# define ll  long long

	const int NN = 1000004;
	int primefactor[NN];
	int arr[NN];int n;
	// vector<pair<int,int>>prime;
	void seive(){

		for(int i=2;i<NN;i++){
			primefactor[i]=i;
		}
		primefactor[0]=1;
		primefactor[1]=1;
		for(int i=2;i*i<NN;i++){
				if(primefactor[i]==i){
					for(int j=2*i;j<NN;j+=i){

							if(primefactor[j]==j){
								primefactor[j]=i;
							}
					}
				}
		}

		// for(int i=2;i<NN;i++){
		// 	if(primefactor[i]==i){
		// 		prime.push_back(i);
		// 	}
		// }
	}
	
	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);  
	  

		seive();
		cin>>n;

		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		map<int,int> ss;
		for(int i=0;i<n;i++){
			int x= arr[i];
			while(x>1){
				int f= primefactor[x];
				// cout<<f<<" "<<x<< "        ";
				ss[f]++;
				x/=f;
				while(x%f==0 && x!=0){
					x=x/f;
				}

			}
			// cout<<endl;
		}
		int pairwise_coprime=1;
		int setwise_coprime=1;
		for(auto itr=ss.begin();itr!=ss.end();itr++){
			if(itr->second>1){
				pairwise_coprime=0;
			}
			if(itr->second==n){
				setwise_coprime=0;
			}
		}
		if(pairwise_coprime){
			cout<<"pairwise coprime"<<endl;
		}
		else if(setwise_coprime){
			cout<<"setwise coprime"<<endl;
		}
		else{
			cout<<"not coprime"<<endl;
		}
	}



	
