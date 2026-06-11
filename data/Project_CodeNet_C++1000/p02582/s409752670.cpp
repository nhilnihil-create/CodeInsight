#include<iostream>
#include<string>

int main()
{
    std::string S;
    std::cin >> S;
    int size=0;
    size=S.size();
    int num,Maxnum=0;

    for(int i=0; i<size ;i++)
    {
        if(S[i]=='R')
        {
            num++;
          	if(num > Maxnum)
            {
            	Maxnum=num;
            }
        }
        if(S[i]=='S')
        {
            num=0;
        }
    }
    std::cout << Maxnum << std::endl;
    return 0;
}