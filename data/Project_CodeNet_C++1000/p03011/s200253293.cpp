#include <iostream>

using namespace std;

int main()
{
    int P,Q,R;
    cin>>P>>Q>>R;
if(P>=1&&Q>=1&&R>=1&&P<=100&&Q<=100&&R<=100){
    if(P+Q<=Q+R && P+Q<=P+R){
        cout<<P+Q;
    }
    else if(Q+R<P+R && Q+R<P+Q){
        cout<<Q+R;
    }
    else {
        cout<<P+R;
    }
}

    return 0;
}