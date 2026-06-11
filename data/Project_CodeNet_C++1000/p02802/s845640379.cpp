#include<bits/stdc++.h>
using namespace std;
bool AC[100005];
int WA[100005];

int main(){
	int n,m;
	cin>>n>>m;
	
	int correct=0;
	int wrong = 0;
	
	while(m--){
		int problem;
		string verdict;
		cin>>problem>>verdict;
		
		
		if(verdict[0]=='A'){
			if(AC[problem]) continue;
			else{
				AC[problem] = true;
				correct++;
              	wrong+=WA[problem];
			}	
		}
		else{
			if(AC[problem]) continue;
			else{
				WA[problem]++;
			}
		}
	}
	cout<<correct<<" "<<wrong<<'\n';
}