#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
        int n;
        cin >> n;
        double s[2000]={0};
        while(n != 0){ 
                double ave=0;
                for( int i = 0; i < n ; i++){
                        cin >> s[i];
                        ave += s[i];
                }   
                ave = ave/n;
                double var=0;
                for( int i = 0; i < n ; i++){
                        var += (s[i] - ave)*(s[i] - ave);
                }   
                var = var/n;    
                cout << setprecision(20);
                cout << showpoint <<  pow(var,0.5) << endl;
                cin >> n;
        }   

return 0;
}