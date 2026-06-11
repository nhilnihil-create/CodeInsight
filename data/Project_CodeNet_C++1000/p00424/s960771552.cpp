#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    while(cin>>n){
	     
	 string s="";

        if(n==0){
            break;
        }
        map<char, char> m;
        char a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            m[a]=b;
        }
        int d;
        cin>>d;
        for(int i=0;i<d;i++){
            cin>>a;
            if(m.count(a)){
                    a=m[a];
                }
            s+=a;
        }
        cout<<s<<endl;
    }
    return 0;
}