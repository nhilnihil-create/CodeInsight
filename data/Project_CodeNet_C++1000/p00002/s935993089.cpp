#include<iostream>

int add(int,int);
int digit (int);

int main()
{
    int a,b;
    while(std::cin >> a >> b)
    {
        std::cout << digit(add(a,b)) << std::endl;
    }
    return 0;
}

int add(int x, int y)
{
    return (x + y);
}

int digit(int num)
{
    int count = 0;
    while(num >= 10){
        num /= 10;
        count++;
    }
    return (count + 1);
}