#include <iostream>
#include <algorithm>
#include<vector>
class Card {
	public:
	//private????????????
	int check;
	char DesignCard;
	int ValueCard;
	//public
	void SetCheck(int InputValueCard, char InputDesignCard, int num);
	int ReturnValue();
};
void Card::SetCheck(int InputValueCard, char InputDesignCard, int num) {
	check = num;
	ValueCard = InputValueCard;
	DesignCard = InputDesignCard;
}
int Card::ReturnValue() {
	return ValueCard;
}
void BubbleSort(std::vector<Card> &InputCard) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (unsigned int i = 0; i < InputCard.size() - 1; ++i) {
			if (InputCard[i].ReturnValue() > InputCard[i+1].ReturnValue()) {
				std::swap(InputCard[i].check, InputCard[i + 1].check);
				std::swap(InputCard[i].DesignCard, InputCard[i + 1].DesignCard);
				std::swap(InputCard[i].ValueCard, InputCard[i + 1].ValueCard);
				flag = true;
			}
		}
	}
}
void SelectSort(std::vector<Card> &InputCard) {
	for (unsigned int i = 0; i < InputCard.size(); ++i) {
		int minj = i;
		for (unsigned int j = i; j < InputCard.size(); ++j) {
			if (InputCard[minj].ReturnValue() > InputCard[j].ReturnValue()) {
				minj = j;
			}
		}
		std::swap(InputCard[i].check, InputCard[minj].check);
		std::swap(InputCard[i].DesignCard, InputCard[minj].DesignCard);
		std::swap(InputCard[i].ValueCard, InputCard[minj].ValueCard);
	}
}
bool stable(std::vector<Card> InputCard) {
	for (unsigned int i = 0; i < InputCard.size() - 1; ++i) {
		if (InputCard[i].ReturnValue() == InputCard[i + 1].ReturnValue()) {
			if (InputCard[i].check > InputCard[i + 1].check) {
				return false;
			}
		}
	}
	return true;
}
void print_stable(bool stable) {
	if (stable == true) {
		std::cout << "Stable" << std::endl;
	}
	else {
		std::cout << "Not stable" << std::endl;
	}
}
void print_array(std::vector<Card> InputCard) {
	for (unsigned int i = 0; i < InputCard.size(); ++i) {
		std::cout << InputCard[i].DesignCard << InputCard[i].ValueCard;
		if (i < InputCard.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}
int main(void) {
	int N;
	std::cin >> N;
	std::vector<int>InputValueCard(N);
	std::vector<char>InputDesignCard(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> InputDesignCard[i] >> InputValueCard[i];
	}
		std::vector<Card> BubbleCARD(N);
	std::vector<Card> SelectCARD(N);
	for (int i = 0; i < N; ++i) {
		BubbleCARD[i].SetCheck(InputValueCard[i], InputDesignCard[i], i);
		SelectCARD[i].SetCheck(InputValueCard[i], InputDesignCard[i], i);
	}
	BubbleSort(BubbleCARD);
	print_array(BubbleCARD);
	print_stable(stable(BubbleCARD));
	SelectSort(SelectCARD);
	print_array(SelectCARD);
	print_stable(stable(SelectCARD));
//	system("pause");
	return 0;
}