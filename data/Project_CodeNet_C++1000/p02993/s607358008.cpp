#include <bits/stdc++.h>
using namespace std;

int main(){

int judge=0;
string S;
cin >> S;
for(int i=0;i<3;i++){
    if(S.at(i)==S.at(i+1)){
        judge=1;
    }
}
if(judge==1){
    cout << "Bad" << endl;
}
else{
    cout << "Good" << endl;
}

}
