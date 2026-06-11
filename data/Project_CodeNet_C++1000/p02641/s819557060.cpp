#include <bits/stdc++.h>
using namespace std;


int main() {
  int x,n;
cin>>x>>n;

int sa=0;
int frag2=0;
vector<int> num(n);
  for(int i=0;i<n;i++)
{
    cin>>num.at(i);

}
for (int i = 0; i < 100; i++)
{
int frag=0;
int frag2=0;
    for (int j = 0; j < n; j++)
    {

        if (num.at(j)==x+i)
        {

         frag++;
         frag2=1;
        }
  if (num.at(j)==x-i)
  {

    frag++;
    frag2=2;
  }

  
    
    }
    if (frag>1)
    {

        sa++;
    }
    else
    {


        if (frag2<2)
        {
            cout<<x-sa<<endl;
        }
        else{
            cout<<x+sa<<endl;
        }
        break;
    }
  
    
}

}