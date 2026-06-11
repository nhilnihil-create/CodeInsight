#include<bits/stdc++.h>
using namespace std;
struct card {char suzi, mozi;};
card hozon[36];
int hyozi(card hai[36],int a){
	for(int i = 0;i<a-1;i++){
		cout<<hai[i].mozi<<hai[i].suzi<<" ";
	}
	cout<<hai[a-1].mozi<<hai[a-1].suzi<<endl;
}
int kakunin(card hai[36],card hozon[36],int a){
	for(int i = 0;i<a;i++){
		if(hai[i].mozi != hozon[i].mozi){
			cout<<"Not stable"<<endl;
			return 0;
		}
	}
	cout<<"Stable"<<endl;
	return 0;
}
 int bubble(card hai[36],int a){
	
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = a-1;i>0;i--){    
            if(hai[i].suzi <hai[i-1].suzi){
                card o;
                o = hai[i];
                hai[i] = hai[i-1];
                hai[i-1] = o;
                flag = 1;
            }
        }
    }
    hyozi(hai,a);
    cout<<"Stable"<<endl;
    for(int i = 0;i<a;i++){
    	hozon[i] = hai[i];
    }
 }
int selection(card hai[36],int a){
	for(int i = 0;i<a-1;i++){
        int minj  =i;
        for(int j = i+1;j<a;j++){
            if(hai[minj].suzi>hai[j].suzi){
                minj = j;
            }
 
        }
        card aho;
        aho = hai[i];
        hai[i]  = hai[minj];
        hai[minj] = aho;
    }
	hyozi(hai,a);
	kakunin(hai,hozon,a);
}
int main(){
	int a;
	cin>>a;
	card hai[a],hai2[a];
	for(int i = 0;i<a;i++){
			cin>>hai[i].mozi>>hai[i].suzi;
	}
	for(int i = 0;i<a;i++){
		hai2[i] = hai[i];
	}
	bubble(hai,a);
	selection(hai2,a);
	return 0;
}
