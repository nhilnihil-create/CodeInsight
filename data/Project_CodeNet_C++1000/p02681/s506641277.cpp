#include <iostream>
#include <string>
using namespace std;

int n;
string idccd, idop, tambah, idakhir;

int main (){
    cin>>idccd>>idop;
    n=idccd.length();
    tambah=idop [n];
    if (idccd+tambah==idop){
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
}