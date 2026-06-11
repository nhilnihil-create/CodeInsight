#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    cin >> s;
    long long int q;
    cin >> q;
    
    for(long long int i=0;i<q;i++){
        string in;
        cin >> in;
        if(in=="print"){
            long long int a,b;
            cin>>a>>b;
            cout<< s.substr(a,b-a+1)<<endl;
            
        }else if(in=="reverse"){
            long long int a,b;
            cin>>a>>b;
            string k=s;
            for(long long int j=a;j<=b;j++){
                s[j]=k[a+b-j];
            }
        }else if (in=="replace"){
            long long int a,b;
            cin>>a>>b;
            for(long long int j=a;j<=b;j++){
                char c;
                cin>>c;
                s[j]=c;
            }
        }
    }
}

