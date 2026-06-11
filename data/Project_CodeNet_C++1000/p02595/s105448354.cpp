#include<iostream>
#include<cmath>
#include<cstdlib>

int main()
{
    int N;
  	int	num=0;
    int i=0;
    double x,y=0;
    double Distance,D=0;

    std::cin >> N >> D;
    double X[N],Y[N]={0};

    for(i=0; i<N; i++)
    {
        std::cin >> X[i] >> Y[i];
        x=X[i]*X[i];
        y=Y[i]*Y[i];
        Distance = std::sqrt(x+y);
        if( Distance <= D)
        {
            num++;
        }
    }
  
    std::cout << num;

    return 0;
}