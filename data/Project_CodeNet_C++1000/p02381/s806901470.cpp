#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector<double> out;

int main(){
    int n;
    do{
        cin>>n;
        if (n!=0){
            int *s;
            s = new int[n];
            if (s==NULL){
                cout<<"Error!"<<endl;
                return -1;
            }
            int i;
            for (i=0;i<n;i++){
                cin>>s[i];
            }
            double ave=0.0;
            for (i=0;i<n;i++){
                ave+=s[i];
            }
            ave/=n;
            double var=0;
            for (i=0;i<n;i++){
                var+=(s[i]-ave)*(s[i]-ave);
            }
            var/=n;
            var=sqrt(var);
            out.push_back(var);
            delete [] s;
        }
    }while (n!=0);
    for (vector<double>::iterator i=out.begin();i!=out.end();i++){
        cout<<fixed<<setprecision(8)<<*i<<endl;
    }
    return 0;
}