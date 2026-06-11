#include <iostream>
using namespace std;

int main(void) 
{
    int A,B,C,K;
    cin >> A >> B >> C;
    cin >> K;
    for(int i=0;i<K;i++){
        if(C<=A || C<=B) C *= 2;
        else if(B<=A) B *= 2;
        else break;
    }
    if(A<B && B<C) printf("Yes");
    else printf("No");
    
}