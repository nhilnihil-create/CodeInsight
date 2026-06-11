#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

int main(){
    string w;
    cin>>w;;
    int result;

    if(w.at(0)=='S' && w.at(1)=='S' && w.at(2)=='S'){
        result = 0;
    }
    else if (w.at(0)=='R' && w.at(1)=='R' && w.at(2)=='R'){
        result = 3;
    }
    else if ((w.at(0)=='R' && w.at(1)=='R' && w.at(2)=='S')||(w.at(0)=='S' && w.at(1)=='R' && w.at(2)=='R')){
        result = 2;
    }
    else{
        result = 1;
    }
    cout<<result<<endl;


}






