#include <iostream>
#include <vector> 
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void shell_sort(vector<int> &p,int n)
{
    int op=0;
    int h_count = 0;
    vector<int> h_array;
    int h,i,j,t,temp;
//    for(h=1;h<=n/9;h=h*3+1);
//    for(h;h>0;h=h/3)
//	{
//        h_count++;
//        h_array.push_back(h); 
//	}
//	cout<<"h's num is' "<<h_count<<endl;

	for(h=1; h<=n; h=h*3+1)
	{
		h_count++;
        h_array.push_back(h); 
	}
	cout<<h_count<<endl;
//	}
	for(int k = h_array.size()-1; k>=0; k--)
	{
		cout<<h_array[k]<<" ";
		if(k==0) cout<<endl;
		
        for(i=h_array[k];i<n;i++)
		{     //???h???1?????¶?????????????????\?????? 
            temp=p[i];
            for(j=i-h_array[k];j>=0&&p[j]>temp;j-=h_array[k])
			{
                p[j+h_array[k]]=p[j];
                op++;
            }
            p[j+h_array[k]]=temp;
        }
	}
	cout<<op<<endl;
}


int main(int argc, char** argv) {	
	int n = 0;
	int count = 0;
	cin>>n;
	vector<int> array;
	while(count<n)
	{
		int input;
		cin>>input;
		count++;
		array.push_back(input);
	}
	
	shell_sort(array, n);   
	
	
	for(int index1 = 0; index1<n; index1++){
		cout<<array[index1]<<endl;
	}
	
	return 0;
}