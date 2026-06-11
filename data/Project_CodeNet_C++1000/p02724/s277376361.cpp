#include <bits/stdc++.h>
#define tt this->
#define ll long long
using namespace std;
int main ()
{
long long x,score=0;
cin>>x;
while (x>=5)
{
    if (x>=500)
    {
        x=x-500;
        score=score+1000;
    }
    else if (x<500)
    {
        x=x-5;
        score=score+5;
    }

}

cout<<score<<endl;
    return 0;
}

/*
▀█████████▄     ▄████████    ▄████████    ▄████████
  ███    ███   ███    ███   ███    ███   ███    ███
  ███    ███   ███    ███   ███    ███   ███    ███
 ▄███▄▄▄██▀    ███    ███  ▄███▄▄▄▄██▀   ███    ███
▀▀███▀▀▀██▄  ▀███████████ ▀▀███▀▀▀▀▀   ▀███████████
  ███    ██▄   ███    ███ ▀███████████   ███    ███
  ███    ███   ███    ███   ███    ███   ███    ███
▄█████████▀    ███    █▀    ███    ███   ███    █▀
                            ███    ███

*/
