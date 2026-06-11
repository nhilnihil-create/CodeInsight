#include <bits/stdc++.h>
using namespace std;

vector<int> verdes,vermelhas,incolores,vazio;
vector<vector<int>> DP;


int main(){
	int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	for (int i = 0; i < a; ++i)
	{
		int val; 
		cin >> val;
		verdes.push_back(val);
	}
	for (int i = 0; i < b; ++i)
	{
		int val; 
		cin >> val;
		vermelhas.push_back(val);
	}
	for (int i = 0; i < c; ++i)
	{
		int val; 
		cin >> val;
		incolores.push_back(val);
	}
	sort(verdes.begin(),verdes.end());
	sort(vermelhas.begin(),vermelhas.end());
	sort(incolores.begin(),incolores.end());
	int ponteiro1=x,ponteiro2=y,ponteiro3=0;
	bool quebraVermelha=false,quebraVerde=false;
	while(verdes[a-ponteiro1]<incolores[c-ponteiro3-1]||vermelhas[b-ponteiro2]<incolores[c-ponteiro3-1]){
		if(verdes[a-ponteiro1]<vermelhas[b-ponteiro2]){
			ponteiro1-=1;
		}else{
			ponteiro2-=1;
		}
		if(ponteiro1<0){
		    ponteiro1=0;
		    quebraVerde=true;
		    break;
		}
		if(ponteiro2<0){
		    ponteiro2=0;
		    quebraVermelha=true;
		    break;
		}
		ponteiro3+=1;
		if(ponteiro3==c){
		    break;
		}
		
	}
	if(quebraVerde){
	    while(vermelhas[b-ponteiro2]<incolores[c-ponteiro3-1]){
	        ponteiro2-=1;
    	    if(ponteiro2<0){
    		    ponteiro2=0;
    		    break;
		    }
		    ponteiro3+=1;
		    if(ponteiro3==c){
    		    break;
    		}
	    }
	}else if(quebraVermelha){
	    while(verdes[a-ponteiro1]<incolores[c-ponteiro3-1]){
	        ponteiro1-=1;
    	    if(ponteiro1<0){
    		    ponteiro1=0;
    		    break;
		    }
		    ponteiro3+=1;
		    if(ponteiro3==c){
    		    break;
    		}
	    }
	}
	long long int total=0;
	for (int i = 1; i <= ponteiro1; ++i)
	{
		total+=verdes[a-i];
	}
	for (int i = 1; i <= ponteiro2; ++i)
	{
		total+=vermelhas[b-i];
	}
	for (int i = 1; i <= ponteiro3; ++i)
	{
		total+=incolores[c-i];
	}
	cout << total;
}