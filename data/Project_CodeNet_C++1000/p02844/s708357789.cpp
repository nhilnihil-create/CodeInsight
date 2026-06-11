#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int fi=0,fj=0,fk=0;
    int count=0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                fi = s.find(to_string(i),0);
                if(fi != string::npos){
                    fj = s.find(to_string(j),fi+1);
                    if(fj != string::npos){
                        fk = s.find(to_string(k),fj+1);
                        if(fk != string::npos){
                            count++;
                         }
                    }
                }
            }   
        }
    }
    cout << count << endl;

    return 0;
}