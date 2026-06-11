#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SCard
{
    char Name;
	int  Value;
};

vector<SCard> BubbleSort(vector<SCard> List);
vector<SCard> Selection(vector<SCard> List);
void Output(vector<SCard> List);
string IsStable(vector<SCard> Org, vector<SCard> After);

int main(){
    int n;
	vector<SCard> List;
	vector<SCard> TempList;
	
    cin >> n;
	
	//???????????\???
	for(int i = 0; i < n; i++){
		SCard Temp;
		cin >> Temp.Name;
		cin >> Temp.Value; 
		List.push_back(Temp);
	}
	TempList.clear();
	TempList = BubbleSort(List);
    Output(TempList);
	cout << IsStable(List, TempList) << endl;

    TempList.clear();
	TempList = Selection(List);
    Output(TempList);
	cout << IsStable(List, TempList) << endl;

}

vector<SCard>  BubbleSort(vector<SCard> List)
{
	for(int i = 0; i < List.size(); i++){
		for(int j = List.size() - 1; j > i; j--){
			if(List[j].Value < List[j-1].Value){
				SCard Temp = List[j];
				List[j] = List[j-1];
				List[j-1] = Temp;
			}
		}
	}
	return List;
}

vector<SCard> Selection(vector<SCard> List)
{
	for(int i = 0; i < List.size(); i++){
		int Min = i;
		for(int j = i; j < List.size(); j++){
			if(List[j].Value < List[Min].Value){
				Min = j;
			}
		}
		SCard Temp = List[i];
		List[i] = List[Min];
		List[Min] = Temp;
	}
	return List;
}

void Output(vector<SCard> List)
{
	for(int i = 0; i < List.size(); i++){
		if(i > 0) cout << " ";
		cout << List[i].Name << List[i].Value;
	}
	cout << endl;
}

string IsStable(vector<SCard> Org, vector<SCard> After)
{
	for(int i = 0; i < Org.size(); i++){
		for(int j = i + 1; j < Org.size(); j++){
			for(int a = 0; a < Org.size(); a++){
				for(int b = a + 1; b < Org.size(); b++){
					if(Org[i].Value == Org[j].Value && Org[i].Name == After[b].Name 
					&& Org[i].Value == After[b].Value && Org[j].Name == After[a].Name
					&& Org[j].Value == After[a].Value){
						return "Not stable";
					}
				}
			}
		}
	}
	return "Stable" ;
}