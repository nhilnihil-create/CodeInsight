#include<iostream>
using namespace std;
class Card
{
    public:
    char suit;
    int num;
};
void BubbleSort(Card icards[],int n)
{
    for(int i=0;i<n;i++)
    for(int j=n-1;j>=i+1;j--)
    {
        if(icards[j-1].num>icards[j].num)
        {
            Card t;
            t=icards[j-1];
            icards[j-1]=icards[j];
            icards[j]=t;
        }
    }
}
void SelectionSort(Card icards[],int n)
{
    for(int i=0;i<n;i++)
    {
        int minj=i;
        for(int j=i;j<n;j++)
        if(icards[j].num<icards[minj].num)
        {
            minj=j;
        }
        Card t=icards[i];
        icards[i]=icards[minj];
        icards[minj]=t;
    }
}
int isStable(Card cards1[],Card cards2[],int n)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(cards1[i].suit!=cards2[i].suit)
        flag = 0;
    }

return flag;
}
int main()
{
    Card cards[36];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cards[i].suit;
        cin>>cards[i].num;
    }

    Card ocards1[36];
    Card ocards2[36];
    for(int i=0;i<n;i++)
    {
    ocards1[i]=cards[i];
    ocards2[i]=cards[i];
    }
    BubbleSort(ocards1,n);
    SelectionSort(ocards2,n);
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<ocards1[i].suit<<ocards1[i].num;
    }
    cout<<endl;
    cout<<"Stable"<<endl;
        for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<ocards2[i].suit<<ocards2[i].num;
    }
    cout<<endl;
    if(isStable(ocards2,ocards1,n))
    {
        cout<<"Stable"<<endl;
    }
    else
    {
        cout<<"Not stable"<<endl;
    }



//cin>>输入进去char 忽略空格！
}

