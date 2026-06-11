#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    flag=false;
    cin >>T;
    
        if (T=="SUN"){
            
            cout <<7 <<endl;
        }
        else if(T=="MON"){
            cout <<6 <<endl;
        }
        else if(T=="TUE"){
            cout <<5 <<endl;
        }
        else if(T=="WED"){
            cout <<4 <<endl;
        }
        else if(T=="THU"){
            cout <<3 <<endl;
        }
        else if(T=="FRI"){
            cout <<2 <<endl;
        }
        else if(T=="SAT"){
            cout <<1 <<endl;
        }
    

    
    

    return 0;
    
}
