#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long double  A,B;
    cin >> A >> B;
    
    int X=-1;
    vector<int> AList(10);
    vector<int> BList(10);
    
    for (int i=0;i<10;i++) {
        AList[i] = 12.5*(A+0.1*i);
        BList[i] = 10*(B+ 0.1*i);
    }
    
    bool end = false;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if(AList[i]==BList[j]) {
                X=AList[i];
                int judge = X*0.08;
                if(judge==A) {
                    end=true;
                    break;
                }
                else {
                    continue;
                }
                
            }
        }
        if(end) {
            break;
        }
    }
    cout << X << endl;
   
}