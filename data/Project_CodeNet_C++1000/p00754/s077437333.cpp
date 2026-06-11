 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
int main(){
    string str;
    while(getline(cin,str),str!="."){
       vector<string>s(1000);
       int num=0;
       bool check=true;
       REP(i,str.size()){
           if(str[i]=='('){
              s[num]="(";
              num++;
           }
           if(str[i]=='['){
              s[num]="[";
              num++;
           }
           if(str[i]==')'){
              if(num==0){
                 check=false;
                 break;
              }
              if(s[num-1]!="("){
                 check=false;
                 break;
              }
              num--;
           }
           if(str[i]==']'){
              if(num==0){
                 check=false;
                 break;
              }
              if(s[num-1]!="["){
                 check=false;
                 break;
              }
              num--;
           }
       }
       if(num!=0)check=false;
       if(check==true){
          cout<<"yes"<<endl;
       }else{
          cout<<"no"<<endl;
       }
    }
    return 0;
}