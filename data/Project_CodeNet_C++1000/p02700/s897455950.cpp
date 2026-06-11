#include <iostream>
int main()
{
    int A,B,C,D;
    std::cin>>A>>B>>C>>D;
    while(A>0 && C>0)
    {
        C=C-B;
        A=A-D;
    }
if(C<=0)
std::cout<<"Yes"<<std::endl;
else
{
    std::cout<<"No"<<std::endl;
}
}