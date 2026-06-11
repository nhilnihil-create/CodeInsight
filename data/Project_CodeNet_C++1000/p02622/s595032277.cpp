#include<iostream>
#include<string>

int main()
{
    std::string S,T;
    std::cin >> S;
    std::cin >> T;
    int size=0;
    int changeNum=0;

    size=S.length();

    for(int i=0; i<size ; i++)
    {
        if(S[i] != T[i])
        {
            T[i]=S[i];
            changeNum++;
        }
    }
    std::cout << changeNum << std::endl;

    return 0;
}