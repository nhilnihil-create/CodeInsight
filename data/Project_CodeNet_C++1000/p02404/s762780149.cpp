#include<iostream>
using namespace std;
 
int main(){
    while(1){
        int d,c;
        cin >> d >>c;
         
        if(d==0 && c==0)break;
        for(int i=0;i<c;i++){
            cout<<"#";
        }
        cout<<"\n";
		
        for(int j=0+1;j<d-1;j++){
            cout<<"#";
            for(int j=0+1;j<c-1;j++){
                cout<<".";
            }
            cout<<"#";
            cout<<"\n";
			
        }
        for(int i=0;i<c;i++){
            cout<<"#";
        }
        cout<<"\n";
        cout<<"\n";
    }
     
    return 0;
}