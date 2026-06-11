#include <iostream>
using namespace std;
int main(){
    int S;
    cin >> S;
    int s;
    s = S % 60;
    
    int m;
    
    m = (S/60)%60;
    
    if (m > 60){
        m = 0;
    }
    
    int h;
    h = S/(60*60);
    cout << h<< ":" << m << ":" << s <<"\n";
}
