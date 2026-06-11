#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
    string a,b;
    for(int j=0;j<n;j++){
    	cin>>a;
        if(a=="0") break;
        int la=a.size();
        int c=0;
        for(int i=0;i<la;i++){
            if(a[i]=='0'){
                if(b=="1"){
                    c=c%5;
                    if(c==1) cout<<".";
                    if(c==2) cout<<",";
                    if(c==3) cout<<"!";
                    if(c==4) cout<<"?";
                    if(c==0) cout<<" "; 
                }
                if(b=="2"){
                    c=c%3;
                    if(c==1) cout<<"a";
                    if(c==2) cout<<"b";
                    if(c==0) cout<<"c";
                }
                if(b=="3"){
                    c=c%3;
                    if(c==1) cout<<"d";
                    if(c==2) cout<<"e";
                    if(c==0) cout<<"f";
                }
                if(b=="4"){
                    c=c%3;
                    if(c==1) cout<<"g";
                    if(c==2) cout<<"h";
                    if(c==0) cout<<"i";
                }
                if(b=="5"){
                    c=c%3;
                    if(c==1) cout<<"j";
                    if(c==2) cout<<"k";
                    if(c==0) cout<<"l";
                }
                if(b=="6"){
                    c=c%3;
                    if(c==1) cout<<"m";
                    if(c==2) cout<<"n";
                    if(c==0) cout<<"o";
                }
                if(b=="7"){
                    c=c%4;
                    if(c==1) cout<<"p";
                    if(c==2) cout<<"q";
                    if(c==3) cout<<"r";
                    if(c==0) cout<<"s";
                }
                if(b=="8"){
                    c=c%3;
                    if(c==1) cout<<"t";
                    if(c==2) cout<<"u";
                    if(c==0) cout<<"v";
                }
                if(b=="9"){
                    c=c%4;
                    if(c==1) cout<<"w";
                    if(c==2) cout<<"x";
                    if(c==3) cout<<"y";
                    if(c==0) cout<<"z";
                }
                c=0;
                b="0";
            }
            else{
                b=a[i];
                c++;
            }
        }
        cout<<endl;
    }
    return 0;
}